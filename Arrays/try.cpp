typedef long long int ll;
#define F first
#define S second
string solution(int A,int B,int C){
    string a="",b="",c="";

                        for(int i=0;i<A;i++){a+='a';}

                        for(int i=0;i<B;i++){b+='b';}
                        for(int i=0;i<C;i++){c+='c';}

    ll cnt[3]={0};
    
    string ans="";
    while(true){
        if((a.size()==0&&b.size()==0)||(c.size()==0&&b.size()==0)||(a.size()==0&&c.size()==0)){
            break;
        } // base conditon
        

        vector<pair<ll,ll>> v;

                v.push_back(make_pair((ll)b.size(),1));
                                v.push_back(make_pair((ll)c.size(),2));
                 v.push_back(make_pair((ll)a.size(),0));

       
       
        sort(v.begin(),v.end());
        if(cnt[v[2].S]!=2){
         ll k=v[2].S;
            if(k==0){
                a.pop_back();
                ans+='a';
                cnt[1]=cnt[2]=0;
                cnt[0]++;
            }
            else if(k==1){
                ans+='b';
                b.pop_back();
                cnt[1]++;cnt[0]=cnt[2]=0;
            }
            else {
                ans+='c';
                c.pop_back();
                cnt[2]++;
                cnt[0]=cnt[1]=0;
            }
        }

        else{
            cnt[v[2].S]=0;

            ll k=v[1].S;
            if(k==0){
                a.pop_back();
                ans+='a';
                cnt[1]=cnt[2]=0;
                cnt[0]++;
                
            }
            else if(k==1){
                b.pop_back();
                ans+='b';
                cnt[0]=cnt[2]=0;
                cnt[1]++;
            }
            else {
                c.pop_back();
                ans+='c';
                cnt[0]=cnt[1]=0;
                cnt[2]++;
                
            }
        }


    }
        if(c.size()>0){
        for(int i=0;i<min((ll)c.size(),2-cnt[2]);i++)
        ans+='c';
    }
        if(b.size()>0){
        for(int i=0;i<min((ll)b.size(),2-cnt[1]);i++)
        ans+='b';
    }
   if(a.size()>0){
        for(int i=0;i<min((ll)a.size(),2-cnt[0]);i++)
        ans+='a';
    }





    return ans;
}