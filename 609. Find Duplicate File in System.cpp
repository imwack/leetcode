/*
Given a list of directory info including directory path, 
and all the files with contents in this directory, 
you need to find out all the groups of duplicate files in the file system in terms of their paths.

A group of duplicate files consists of at least two files 
that have exactly the same content.

A single directory info string in the input list has the following format:

"root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ... fn.txt(fn_content)"

It means there are n files 
(f1.txt, f2.txt ... fn.txt with content f1_content, f2_content ... fn_content, respectively) 
in directory root/d1/d2/.../dm. 
Note that n >= 1 and m >= 0. If m = 0, it means the directory is just the root directory.

The output is a list of group of duplicate file paths. For each group,
it contains all the file paths of the files that have the same content. 
A file path is a string that has the following format:

"directory_path/file_name.txt"

Example 1:
Input:
["root/a 1.txt(abcd) 2.txt(efgh)", "root/c 3.txt(abcd)", "root/c/d 4.txt(efgh)",
 "root 4.txt(efgh)"]
Output:  
[["root/a/2.txt","root/c/d/4.txt","root/4.txt"],["root/a/1.txt","root/c/3.txt"]]
*/

class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        vector<vector<string>> ret;
        map<string,vector<string>>   m; //content -> filename
        for(string path:paths){
            //"root/a 1.txt(abcd) 2.txt(efgh)"
            stringstream ss;
            string dir,temp;
            ss<<path;
            ss>>dir;
            while(ss>>temp){
                //1.txt(abcd)
                int pos = temp.find('(');
                string filename(temp,0,pos);
                filename = dir+'\/'+filename;
                string content(temp,pos+1,temp.size()-pos-2);
                if(m.find(content)==m.end()){
                    vector<string> temp;
                    temp.push_back(filename);
                    m[content] = temp;
                }else{
                    m[content].push_back(filename);
                }
            }
        }
        for(auto it=m.begin();it!=m.end();it++){
            if((it->second).size()>1)
            ret.push_back(it->second);
        }
        return ret;
    }
};