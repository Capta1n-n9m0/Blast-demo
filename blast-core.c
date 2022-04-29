#include "blast-core.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

best_match process_matches(const char *sMatches) {
	int nLength = strlen(sMatches);
	int nMax_global = -1, nMax_local = 0;
	int nGlobal_max_start = 0, nLocal_max_start = 0;
	for (int i = 0; i < nLength; i++) {
		if (sMatches[i] == '1') nMax_local++; else nMax_local--;
		if (nMax_global < nMax_local) {
			nMax_global = nMax_local;
			nGlobal_max_start = nLocal_max_start;
		}
		if (nMax_local < 0) {
			nMax_local = 0;
			nLocal_max_start = i;
		}
	}
	return (best_match) {nGlobal_max_start + 1, nMax_global};
}

best_match get_blast_matches(const char *sData, const char *sTarget) {
	int nData_length = strlen(sData), nTarget_length = strlen(sTarget);
	int nMax_global = -1, nMax_local = 0;
	int nGlobal_max_start = 0, nLocal_max_start = 0;
	for (int i = 0; i < nData_length - nTarget_length; i++) {
		for (int j = 0; j < nTarget_length; j++) {
			if (sData[i + j] == sTarget[j]) nMax_local++; else nMax_local--;
			if (nMax_global < nMax_local) {
				nMax_global = nMax_local;
				nGlobal_max_start = nLocal_max_start;
			}
			if (nMax_local < 0) {
				nMax_local = 0;
				nLocal_max_start = i + j;
			}
		}
		nMax_local = 0;
	}
	return (best_match) {nGlobal_max_start, nMax_global};
}


