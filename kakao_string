#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.length();
    int max_ele = s.length()/2;
    
    for(int unit_len = 1; unit_len <= max_ele; unit_len++){
        vector <string> v;
        int str_cnt;
        string new_str = "";
        
        
        //문자열이 sub_str 몇개로 나누어져 있는지 구함
        if(s.length() % unit_len == 0){
            str_cnt = s.length() / unit_len;
        }else{
            str_cnt = s.length() / unit_len + 1;
        }
        
       
        //벡터에 문자군으로 push
        for(int i =0; i < str_cnt; i++){
            v.push_back(s.substr(i*unit_len, unit_len));
        }
        
        //문자군들을 비교, new_str에 차곡차곡 넣는다
        for(int i=0; i< str_cnt; i++){
            int j;
            for(j= i+1; j < str_cnt; j++){
                if(v[i].compare(v[j]) != 0){
                    break;
                }
            }
            
            if(j == i+1){ //즉, 바로 다음 문자열과 같이 않다!
                new_str = new_str + v[i];
            }
            else{
                new_str = new_str + to_string(j-i) + v[i];
                i = j-1; //i++을 만나기 때문에 하나 적은 값을 취한다
            }
            
        }
        
        answer = (answer > new_str.length()) ? new_str.length() : answer;
    }
    

    return answer;
}
