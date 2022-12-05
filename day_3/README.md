# Day 3

My first reaction was to convert each string into a set of chars and then use set intersections to find common elements.

    string -> set<char>  
    intersection(set<char>, set<char>)
    
I was unable to figure out why the compiler was so angry about different type conversions. When do I use `const` or `*` modifiers?

    vJrwpWtwJgWrhcsFMMfFFhFp
    jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL
    PmmdzqPrVvPwwTWBwg
    wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn
    ttgJtRGJQctTZtZT
    CrZsJsPPZsGzwwsLwLmpwMDw

## Part 1
`./rucksack_pt1 ./data/input.txt`
## Part 2
