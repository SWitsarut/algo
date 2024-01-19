package muldac

import (
	"fmt"
	"math"
	"strconv"
)

func Mul(aStr string, bStr string) int {
	a, _ := strconv.Atoi(aStr)
	b, _ := strconv.Atoi(bStr)
	var n int = len(aStr)
	if n == 1 {
		return a * b
	} else {
		a1 := aStr[:n/2]
		a2 := aStr[n/2:]
		b1 := bStr[:n/2]
		b2 := bStr[n/2:]
		A := Mul(a1, b1)
		B := Mul(a2, b1)
		C := Mul(a1, b2)
		D := Mul(a2, b2)
		var nF float64 = float64(n)
		return A*int(math.Pow(10, nF)) + (B+C)*int(math.Pow(10, nF/2)) + D
	}
}

func Main() {
	a := "4568"
	b := "3275"
	// a := "0100"
	// b := "0100"
	aInt, _ := strconv.Atoi(a)
	bInt, _ := strconv.Atoi(b)

	ans := Mul(a, b)
	realAns := aInt * bInt
	fmt.Println("dac mul result\t", ans)
	fmt.Println("real value is\t", realAns)
	fmt.Println("is equal\t", ans == realAns)
}
