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

void testFindNextWord() {
	T* text = NULL;
	CU_ASSERT_PTR_NULL(findNextWord(text));
	text = "";
	CU_ASSERT_PTR_NULL(findNextWord(text));
	text = "bebe";
	CU_ASSERT_PTR_NULL(findNextWord(text));
	text = "bebe be";
	CU_ASSERT_STRING_EQUAL(findNextWord(text), "be");
	text = "bebe be be";
	CU_ASSERT_STRING_EQUAL(findNextWord(text), "be be");
	text = " bebe be";
	CU_ASSERT_STRING_EQUAL(findNextWord(text), "bebe be");
}

void testFindFirstWord() {
	T* text = NULL;
	CU_ASSERT_PTR_NULL(findFirstWord(text));
	text = "";
	CU_ASSERT_PTR_NULL(findFirstWord(text));
	text = " ..; ";
	CU_ASSERT_PTR_NULL(findFirstWord(text));
	text = "bebe";
	CU_ASSERT_STRING_EQUAL(findFirstWord(text), "bebe");
	text = " bebe be";
	CU_ASSERT_STRING_EQUAL(findFirstWord(text), "bebe be");
}
