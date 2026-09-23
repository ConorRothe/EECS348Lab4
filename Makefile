all: football_scores temperature

football_scores: football_scores.c
	gcc football_scores.c -o football_scores

temperature: temperature.c
	gcc temperature.c -o temperature

clean:
	rm -f football_scores temperature