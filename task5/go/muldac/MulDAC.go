package muldac

import (
	"fmt"
	"math"
	"strconv"
)

func Mul(a int, b int) int {
	var aStr string = fmt.Sprintf("%d", a)
	var bStr string = fmt.Sprintf("%d", b)
	var n int = len(aStr)
	if n == 1 {
		return a * b
	} else {
		a1, _ := strconv.Atoi(aStr[:n/2])
		a2, _ := strconv.Atoi(aStr[n/2:])
		b1, _ := strconv.Atoi(bStr[:n/2])
		b2, _ := strconv.Atoi(bStr[n/2:])
		A := Mul(a1, b1)
		B := Mul(a2, b1)
		C := Mul(a1, b2)
		D := Mul(a2, b2)
		var nF float64 = float64(n)
		return A*int(math.Pow(10, nF)) + (B+C)*int(math.Pow(10, nF/2)) + D
	}
}

func Main() {
	a := 30
	b := 10
	ans := Mul(a, b)
	fmt.Println(ans)
}
