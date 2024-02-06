package main

import (
	"fmt"
	"math/rand"
	"os"
	"strconv"
)

func convert(str string, name string) int64 {
	valInt, err := strconv.ParseInt(str, 10, 64)
	if err != nil {
		panic(fmt.Sprintf("expect <%s> value as int number", name))
	}
	return valInt
}

func main() {
	args := os.Args
	var count int64 = 10
	var minBound int64 = 0
	var maxBound int64 = 100

	size := len(args)

	if size > 1 {
		count = convert(args[1], "count")
	}
	if size == 4 {
		minBound = convert(args[2], "min")
		maxBound = convert(args[3], "max")
		if minBound > maxBound {
			panic("<min> had to be less than <max>")
		}
	} else if size != 1 {
		panic("Usage: randnum <count> <min> <max>")
	}

	for i := 0; i < int(count); i++ {
		randomed := rand.Intn(int(maxBound-minBound+1)) + int(minBound)
		fmt.Print(randomed, " ")
	}
	fmt.Print("\n")
}
