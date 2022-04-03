//
// Created by Gabi Bondi on 31/03/2022.
//

#ifndef Q2_REPOSITORY_H
#define Q2_REPOSITORY_H

class Repository {
    HashClient hashClient;
    HashVolunteer hashVolunteer;

    Repository(){
        hashClient = new HashTbls(100);
        hashVolunteer = new HashTbls(100);
    }
};

#endif //Q2_REPOSITORY_H

/*class hashint : public HashTbls<int,int>{

public:
    hashint(int size): HashTbls(size){};

    int h1(int key){
        for(int i =0; i < tableSize; i++){
            if(item[i].key == key ) return i;
        }
        return -1;
    }

    int h2(int key){ return floor(key*tableSize);}
};*/
