#!/bin/bash
# KaldiBasedSpeakerVerification
# test1Enroll.sh
# ========================================
# Author: Qianhui Wan
# Version: 1.0.0
# Date   : 2018-01-23
# ========================================
# The following lines will setup the path to each lib
# path to kaldi/src/lib
export LD_LIBRARY_PATH=/home/dnlam/sourceCode/vnpt/NCKH/kaldi/src/lib:$LD_LIBRARY_PATH
# path to altas
export LD_LIBRARY_PATH=/usr/lib64/atlas:$LD_LIBRARY_PATH
# path to openfst
export LD_LIBRARY_PATH=/home/dnlam/sourceCode/vnpt/NCKH/kaldi/tools/openfst/lib:$LD_LIBRARY_PATH
# path to usr/local/lib
export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH


datadir=./example_data/enroll

for speaker in $datadir/*; do
	speakerName=$(basename $speaker);
	echo "speaker: " $speaker
	echo "speakerName: " $speakerName
	for audio in $speaker/*.wav; do
		echo "audio " $audio
		../enroll $speakerName $audio;
	done
done


