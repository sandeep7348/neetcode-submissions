class Solution {
public:
     void buildHelper(int index,string digits,string intialCombination,vector<string> &totalCombination,string digitsArray[])
     {
        if(index==digits.length())
        {
           totalCombination.push_back(intialCombination);
            return;
        }
        string stringtoCharArray=digitsArray[digits[index]-'0'];
        for(int i=0;i<stringtoCharArray.length();i++)
        {
            buildHelper(index+1,digits,intialCombination+stringtoCharArray[i],totalCombination,digitsArray);
        }

     }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; 
        string digitsArray[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> totalCombination;
        buildHelper(0,digits,"",totalCombination,digitsArray);
        return totalCombination;
        
    }
};