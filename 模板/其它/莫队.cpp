for(; r < q[i].r; r++) add(r + 1, 1);
for(; r > q[i].r; r--) add(r, -1);
for(; l < q[i].l; l++) add(l, -1);
for(; l > q[i].l; l--) add(l - 1, 1);
for(; t < q[i].k; t++) Update(upd[t + 1]);
for(; t > q[i].k; t--) Update(upd[t]);
