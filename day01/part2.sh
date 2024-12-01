INPUT=$(cat cleaned_input.txt)

L1=$(printf "%b" "$INPUT" | awk '{print $1}' | sort -n)
L2=$(printf "%b" "$INPUT" | awk '{print $2}' | sort -n)

L1_ARRAY=($L1)
L2_ARRAY=($L2)

SUM=0

for i in ${!L1_ARRAY[@]}; do
	for j in ${!L2_ARRAY[@]}; do
		if [ "${L1_ARRAY[$i]}" = "${L2_ARRAY[$j]}" ]; then
			SUM=$(( $SUM + ${L1_ARRAY[$i]} ))
		fi
	done
done

echo $SUM

