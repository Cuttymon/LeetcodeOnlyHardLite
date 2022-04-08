func findSubstring(s string, words []string) []int {
	if len(words) == 0 || len(s) == 0 {
		return []int{}
	}
	wordLen := len(words[0])
	wordNum := len(words)
	s_len := len(s)
	wordMap := map[string]int{}
	for _, word := range words {
		wordMap[word]++
	}
	res := []int{}
	for i := 0; i < wordLen; i++ {
		cnt := 0
		copy := copymap(wordMap)
		for j := i; j <= s_len-wordLen; j += wordLen {
			sub := s[j : j+wordLen]
			copy[sub]--
			if copy[sub] >= 0 {
				cnt++
			}
			popstart := j - wordNum*wordLen
			if popstart >= 0 {
				pop := s[popstart : popstart+wordLen]
				copy[pop]++
				if copy[pop] > 0 {
					cnt--
				}
			}
			if cnt == wordNum {
				res = append(res, popstart+wordLen)
			}
		}
	}
	return res
}
func copymap(m map[string]int) map[string]int {
	res := map[string]int{}
	for k, v := range m {
		res[k] = v
	}
	return res
}