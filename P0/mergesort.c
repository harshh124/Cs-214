#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "Sorter.h"
#include<math.h>
struct mData *temp;
int changePos(struct mData **records, int left, int right) {
	//struct mData *temp = malloc(2 * sizeof *records);
	struct mData temp;
	temp = (*records)[left];
	(*records)[left] = (*records)[right];
	(*records)[right] = temp;
	return 0;
}
void Merge(struct mData records[], void** pray, int sF, char* field, int left,
		int mid, int right, int size) {
	printf(
			"**********************************************************************************\n");
	int dataField = ((int *) pray)[0];
//	printf("The dataField is %d\n", dataField);
	int i = left;
	int j = mid;
	int m = mid + 1, n = right;
	char* one;
	char* two;
	int numOne;
	int numTwo;
	float flowOne;
	float flowTwo;

	if (dataField == 0) {
		//printf("The dataField 'strings' is %d\n", dataField);
		while (i <= j && m <= n) {
			//printf("The cpyLeft side is %s\n", Left[i]);
			//printf("The cpyRight side is %s\n", Right[i]);
			one = (char *) pray[i];
			two = (char *) pray[m];
			printf("one is %s\n", one);
			printf("two is %s\n", two);

			if ((strcmp(one, two)) <= 0) {
				printf("The cmp is %d\n", strcmp(one, two));
				i++;
				//changePos(&records, m++, i++);

			} else {
				printf("switching %s and %s\n", one, two);
				changePos(&records, m, i);
				printf("switched\n");
				i++;
				m++;

				int x;
				 for (x = 1; x < size + 1; x++) {
				 printf("Movie title : %s\n",records[x].mTitle);
				 }


			}

		}

		while (i < j) {
			//printf("im in t-2\n");
			i++;
		}

		while (m < n) {
			printf("im in t-1\n");
			Merge(records, pray, sF, field, m - 1, m, n, size);
			int x;
			for (x = 1; x < size + 1; x++) {
				printf("Movie title : %s\n", records[x].mTitle);
			}

			m++;
		}

	}
	if (dataField == 1) {
		//printf("The dataField 'ints' is %d\n", dataField);
		while (i <= j && m <= n) {
			//printf("The cpyLeft side is %s\n", Left[i]);
			//printf("The cpyRight side is %s\n", Right[i]);
			numOne = *(int*) pray[i];
			numTwo = *(int*) pray[m];
			//		printf("one is %d\n", numOne);
			//		printf("two is %d\n", numTwo);

			if (numOne < numTwo) {
				//			printf("The cmp is %d\n", strcmp(pray[i], pray[j]));
				i++;
				//changePos(&records, m++, i++);
				//strcpy(records[k++].mTitle, Left[i++]);
			} else {
				//			printf("switching %s and %s\n",one,two);
				changePos(&records, m, i++);
				//int sum = ((m-1)+n)/2;
				//Merge(records, pray, sF, field, m-1, sum, n, size);
				//			printf("switched\n");

				//			int x;
				//			for (x = 1; x < size + 1; x++) {
				//				 printf("Movie title : %s\n",records[x].mTitle);
			}
			//changePos(&records, k++, m++);
			//strcpy(records[k++].mTitle, Right[j++]);
		}

		while (i < j) {
			//printf("im in t-2\n");
			i++;
			n++;
		}

		while (m < n) {
			//printf("im in t-1\n");
			Merge(records, pray, sF, field, m - 1, m, n, size);
			m++;
			j++;
		}
	}
	if (dataField == 2) {
		//printf("The dataField 'floats' is %d\n", dataField);
		while (i <= j && m <= n) {
			//printf("The cpyLeft side is %s\n", Left[i]);
			//printf("The cpyRight side is %s\n", Right[i]);
			flowOne = *(float*) pray[i];
			flowTwo = *(float*) pray[m];
			//		printf("one is %d\n", numOne);
			//		printf("two is %d\n", numTwo);

			if (flowOne < flowTwo) {
				//			printf("The cmp is %d\n", strcmp(pray[i], pray[j]));
				i++;
				//changePos(&records, m++, i++);
				//strcpy(records[k++].mTitle, Left[i++]);
			} else {
				//			printf("switching %s and %s\n",one,two);
				changePos(&records, m, i++);
				//int sum = ((m-1)+n)/2;
				//Merge(records, pray, sF, field, m-1, sum, n, size);
				//			printf("switched\n");

				//			int x;
				//			for (x = 1; x < size + 1; x++) {
				//				 printf("Movie title : %s\n",records[x].mTitle);
			}
			//changePos(&records, k++, m++);
			//strcpy(records[k++].mTitle, Right[j++]);
		}

		while (i < j) {
			//printf("im in t-2\n");
			i++;
			n++;
		}

		while (m < n) {
			//printf("im in t-1\n");
			Merge(records, pray, sF, field, m - 1, m, n, size);
			m++;
			j++;
		}
	}

	/*printf("address of 1 is %p\n", pray[1]);
	 printf("address of 2 is %p\n", pray[2]);
	 printf("address of 3 is %p\n", pray[3]);*/

	/*if ((strcmp(one, two)) < 0) {
	 printf("one is %s\n", one);
	 printf("two is %s\n", two);
	 printf("less than \n");
	 }*/

}

void MergeSort(struct mData records[], void** pray, int sF, char * field,
		int left, int right) {

	int size = right;
	int sum;
	/*printf("The field is %s\n", field);
	 printf("The left is %d\n", left);
	 printf("The right is %d\n", right);*/
	printf("Movie title first : %s\n", records[left].mTitle);
	printf("Movie title last : %s\n", records[right].mTitle);

	if (left < right) {
		printf(
				"----------------------------------------------------------------------------------\n");
		printf("The 2 left is %d\n", left);
		printf("The size/right is %d\n", size);
		sum = left + right;

		int mid = ((left + right) / 2);
		printf("The sum 1 is %d\n", sum);
		printf("The mid 1 is %d\n", mid);
		MergeSort(records, pray, sF, field, left, mid);
		printf("The mid2 is %d\n", mid);
		MergeSort(records, pray, sF, field, mid + 1, right);
//		printf("before merge mid is %d\n", mid);
//		printf("before merge right is %d\n", right);
//		printf("before merge left is %d\n", left);
		Merge(records, pray, sF, field, left, mid, right, size);
	}

}

void Print(struct mData records[], int size) {
	printf(
			"color,director_name,num_critic_for_reviews,duration,director_facebook_likes,actor_3_facebook_likes,"
					"actor_2_name,actor_1_facebook_likes,gross,genres,actor_1_name,movie_title,num_voted_users,cast_total_facebook_likes,"
					"actor_3_name,facenumber_in_poster,plot_keywords,movie_imdb_link,num_user_for_reviews,language,country,content_rating,budget,"
					"title_year,actor_2_facebook_likes,imdb_score,aspect_ratio,movie_facebook_likes\n");
	int i;
	for (i = 1; i < size; i++) {
		//printf(" Movie %s. \n",  records[i].mTitle);

		printf(
				"%s,%s,%d,%d,%d,%d,%s,%d,%d,%s,%s,%s,%d,%d,%s,%d,%s,%s,%d,%s,%s,%s,%d,%d,%d,%g,%g,%d\n",
				records[i].color, records[i].dName, records[i].review,
				records[i].duration, records[i].dFbLikes, records[i].a3FbLikes,
				records[i].a2Name, records[i].a1FbLikes, records[i].gross,
				records[i].genres, records[i].a1Name, records[i].mTitle,
				records[i].votes, records[i].castFbLikes, records[i].a3Name,
				records[i].facenum, records[i].plot, records[i].movielink,
				records[i].userReview, records[i].language, records[i].country,
				records[i].cRating, records[i].budget, records[i].tYear,
				records[i].a2FbLikes, records[i].imdbScore, records[i].aRatio,
				records[i].movieFbLikes);
		//printf("\n");

	}
}

