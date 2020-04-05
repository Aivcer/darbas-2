# darbas-2

*Kompiuteris*

CPU: AMD Ryzen 5 2600

HD: 1 TB 7200 rpm

GPU: AMD RX580 4gb

RAM: 16gb ddr4

V1.0

Didziausia problema tai kad programa naudoja tik iki 2GB RAM, del ko 10 milijonu duomenu negaliu nuskaityti, meta klaida. Kiek klausiau zmoniu, tai cia windows problema ir ja spresti nelabai yra kaip, gal klystu.

---

Strategija 1 
| Size     	| Vector        	| Deque        	| List          	|
|----------	|---------------	|--------------	|---------------	|
| 1000     	| 0.003003 s    	| 0.005005 s   	| 0.003012 s    	|
| 10000    	| 0.024022 s    	| 0.045041 s   	| 0.030018 s    	|
| 100000   	| 0.238216 s    	| 0.442401 s   	| 0.309289 s    	|
| 1000000  	| 2.32913 s     	| 4.43591 s    	| 3.03486 s     	|
| 10000000 	| neuztenka RAM 	| neuztenka RA 	| neuztenka RAM 	|

Rezultatai- vector greiciausias, list antroje vietoje, deque blogiausias.

---

Strategija 2
| Size     	| Vector        	| Deque        	| List          	|
|----------	|---------------	|--------------	|---------------	|
| 1000     	| 0.084076 s    	| 0.026024 s   	| 0.00201 s     	|
| 10000    	| 8.35681 s     	| 2.54732 s   	| 0.017016 s    	|
| 100000   	| nesulaukiau   	| 257.1 s       | 0.168318 s      |
| 1000000  	| nesulaukiau    	| nesulaukiau  	| 1.73258 s       |
| 10000000 	| nesulaukiau    	| nesulaukiau 	| neuztenka RAM   |

Rezultatai- list geriausias, deque antroje vietoje, vector blogiausias. List labai greitas, o kiti 2 labai leti.

---

