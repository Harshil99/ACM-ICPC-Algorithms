li N=1e5;
    
vi seg(2*N);
vi a;

li n;
 
void build() 
{
    f(i,0,n-1)
    {
        seg[i+n]=a[i];
    }

    fr(i,n-1,1)
    {
        seg[i] = seg[i<<1] + seg[i<<1|1];
    }
}

void update(li p,li val) 
{
    for(seg[p += n] = val; p > 1; p >>= 1) seg[p>>1] = seg[p] + seg[p^1];
}

li query(li l,li r) 
{
  li res = 0;
  
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) 
  {
    if (l&1) res += seg[l++];
    if (r&1) res += seg[--r];
  }

  return res;
}