#ifndef BLAST_DEMO_BLAST_CORE_H
#define BLAST_DEMO_BLAST_CORE_H


typedef struct best_match_ {
	int nPos, nScore;
} best_match;

best_match process_matches(const char *sMatches);

best_match get_blast_matches(const char *sData, const char *sTarget);


#endif //BLAST_DEMO_BLAST_CORE_H
