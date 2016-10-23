#!/bin/sh

VOTE_BIN=./Vote
BRACKETS_BIN=./Brackets
VOTE_DIR=Vote_testcase
BRACKETS_DIR=Brackets_testcase

rm -f $VOTE_DIR/diff.txt
for input in `ls $VOTE_DIR/*input.txt`; do
    cat $input | $VOTE_BIN > ${input/input/output_my}
    echo -n "Check the $VOTE_BIN( $input ) file : "
    diff -b ${input/input/output} ${input/input/output_my} >> $VOTE_DIR/diff.txt
    if [ $? -eq 0 ]; then
        echo OK
    else
        echo Difference
        echo $input >> $VOTE_DIR/diff.txt
    fi
done

rm -f $BRACKETS_DIR/diff.txt
for input in `ls $BRACKETS_DIR/*input.txt`; do
    cat $input | $BRACKETS_BIN > ${input/input/output_my}
    echo -n "Check the $BRACKETS_BIN( $input ) file : "
    diff -b ${input/input/output} ${input/input/output_my} >> $BRACKETS_DIR/diff.txt
    if [ $? -eq 0 ]; then
        echo OK
    else
        echo Difference
        echo $input >> $BRACKETS_DIR/diff.txt
    fi
done

