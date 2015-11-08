#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Basic.h>
#include "../tasks_array.h"
#include "tests.h"

void testCountWordsArray() {
	T* array = "bebe";
	CU_ASSERT_EQUAL(countWordsArray(array), 1);
	array = " ";
	CU_ASSERT_EQUAL(countWordsArray(array), 0);
	array = "bebe  bebe";
	CU_ASSERT_EQUAL(countWordsArray(array), 2);
	array = "bebe, arar... murr	murr;";
	CU_ASSERT_EQUAL(countWordsArray(array), 4);
	array = "";
	CU_ASSERT_EQUAL(countWordsArray(array), 0);
	array = NULL;
	CU_ASSERT_EQUAL(countWordsArray(array), 0);
}

void testWordlen() {
	T* word = NULL;
	CU_ASSERT_EQUAL(wordlen(word), 0);
	word = "";
	CU_ASSERT_EQUAL(wordlen(word), 0);
	word = " ";
	CU_ASSERT_EQUAL(wordlen(word), 0);
	word = "bebe";
	CU_ASSERT_EQUAL(wordlen(word), 4);
	word = "bebe  bebe";
	CU_ASSERT_EQUAL(wordlen(word), 4);
}

void testCmpWithFirstWord() {
	T *firstWord = "bebe", *word = NULL;
	CU_ASSERT_EQUAL(cmpWithFirstWord(firstWord, word), 0);
	word = "be";
	CU_ASSERT_EQUAL(cmpWithFirstWord(firstWord, word), 0);
	word = "murr";
	CU_ASSERT_EQUAL(cmpWithFirstWord(firstWord, word), 0);
	word = "beee";
	CU_ASSERT_EQUAL(cmpWithFirstWord(firstWord, word), 0);
	word = "bebe";
	CU_ASSERT_EQUAL(cmpWithFirstWord(firstWord, word), 1);
	word = "bebe     fe fefe";
	CU_ASSERT_EQUAL(cmpWithFirstWord(firstWord, word), 1);
}
