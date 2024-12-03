if test -f cleaned_input.txt; then
	INPUT=$(cat cleaned_input.txt)
else
	INPUT="3   4\n4   3\n2   5\n1   3\n3   9\n3   3"
fi


L1=$(printf "%b" "$INPUT" | awk '{print $1}' | sort -n)
L2=$(printf "%b" "$INPUT" | awk '{print $2}' | sort -n)

L1_ARRAY=($L1)
L2_ARRAY=($L2)

SUM=0

for i in ${!L1_ARRAY[@]}; do
	DIFF=$(( ${L1_ARRAY[$i]} - ${L2_ARRAY[$i]} ))
	DIFF=${DIFF#-} #get absolute value
	SUM=$(( $SUM + $DIFF ))
	#echo $SUM
done

echo $SUM

