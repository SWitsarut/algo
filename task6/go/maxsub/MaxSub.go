package maxsub

// import (
// 	"fmt"
// 	"math"
// )

// func Max_Subarray_sum(arr []int) int {
// 	n := len(arr)
// 	if n == 1 {
// 		return arr[0]
// 	} else {
// 		m := n / 2
// 		lmss := Max_Subarray_sum(arr[:m])
// 		rmss := Max_Subarray_sum(arr[m:])

// 		lsum := math.MinInt32
// 		rsum := math.MinInt32
// 		sum := 0
// 		for i := 0; i < n; i++ {
// 			sum += arr[i]
// 			rsum = int(math.Max(float64(rsum), float64(sum)))
// 		}
// 		sum = 0
// 		for i := m - 1; i >= 0; i-- {
// 			sum += arr[i]
// 			lsum = int(math.Max(float64(lsum), float64(sum)))
// 		}
// 		return max(max(lmss, rmss), lsum+rsum)
// 	}
// }
// func Main() {
// 	arr := []int{16, -25, 2, -54, 36, 9, -12, 66}
// 	fmt.Println(Max_Subarray_sum(arr))
// }
