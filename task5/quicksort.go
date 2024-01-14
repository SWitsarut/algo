package main

import "fmt"

func partition(arr []int) int {
	p := arr[0]
	i := 0
	j := len(arr) - 1
	for true {
		for true {
			if arr[i] >= p {
				break
			} else {
				i++
			}
		}
		for true {
			if arr[j] <= p {
				break
			} else {
				j--
			}
		}
		arr[i], arr[j] = arr[j], arr[i]
		if i >= j {
			break
		}
	}
	arr[i], arr[j] = arr[j], arr[i]
	return j
}

func quickSort(arr []int) {
	if len(arr) > 1 {
		m := partition(arr)
		quickSort(arr[:m])
		quickSort(arr[m+1:])
	}
}

func main() {
	arr := []int{16, 25, 2, 54, 36, 9, 12, 66}
	quickSort(arr)
	fmt.Println(arr)
}
