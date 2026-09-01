class Directory{
public:
    map<string, Directory> sub_directories;
    map<string, string> files;
    Directory(){
    }
};

class FileSystem {
public:
    Directory root;
    FileSystem() {
        root = Directory();
    }
    
    vector<string> ls(string path) {
        vector<string> ret;
        string cur;
        Directory* cur_dir = &root;
        for (int i =0; i<path.size();i++){
            if (path[i]=='/'){
                if (cur != ""){
                    cur_dir = &cur_dir->sub_directories[cur];
                }
                cur = "";
            } else {
                cur += path[i];
            }
        }
        if (cur_dir->sub_directories.contains(cur)){
            cur_dir = &cur_dir->sub_directories[cur];
        } else if (cur_dir->files.contains(cur)){
            ret.push_back(cur);
            return ret;
        }
        for (auto[file,str]:cur_dir->files){
            ret.push_back(file);
        }
        for (auto[sub_dir, d]: cur_dir->sub_directories){
            ret.push_back(sub_dir);
        }
        sort(ret.begin(),ret.end());
        return ret;
    }
    
    void mkdir(string path) {
        string cur;
        Directory* cur_dir = &root;
        for (int i =0; i<path.size();i++){
            if (path[i]=='/'){
                if (cur != ""){
                    if (!cur_dir->sub_directories.contains(cur)){
                        cur_dir->sub_directories[cur] = Directory();
                    }
                    cur_dir = &cur_dir->sub_directories[cur];
                }
                cur = "";
            } else {
                cur += path[i];
            }
        }
        if (!cur_dir->sub_directories.contains(cur)){
            cur_dir->sub_directories[cur] = Directory();
        }

    }
    
    void addContentToFile(string filePath, string content) {
        string cur;
        Directory* cur_dir = &root;
        for (int i =0; i<filePath.size();i++){
            if (filePath[i]=='/'){
                if (cur != ""){
                    cur_dir = &cur_dir->sub_directories[cur];
                }
                cur = "";
            } else {
                cur += filePath[i];
            }
        }
        cur_dir->files[cur] += content;
    }
    
    string readContentFromFile(string filePath) {
        string cur;
        Directory* cur_dir = &root;
        for (int i =0; i<filePath.size();i++){
            if (filePath[i]=='/'){
                if (cur != ""){
                    cur_dir = &cur_dir->sub_directories[cur];
                }
                cur = "";
            } else {
                cur += filePath[i];
            }
        }
        return cur_dir->files[cur];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */
