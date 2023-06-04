#Nicholas Bright njb0130
BEGIN{
FS=","
printf("\nStudent Average Test Scores\n");
printf("Name           Average\n");
Count=0
Score=0
}
{
	if($3 == "A"){
		avg=(($4+$5+$6)/3)
	name=$2" "$1
	printf("%-13s %5.1f\n", name, avg);
	Count++;
	Score += avg
	}
}
END{
	printf("%d Students with the average score of %.1f\n", Count, (Score/Count));
	}


