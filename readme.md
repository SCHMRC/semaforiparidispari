# Esercizio con Semafori e Thread in C++

Questo progetto contiene un semplice programma C++ che utilizza **thread** e **semafori POSIX** per alternare l'esecuzione di due funzioni: una che gestisce i numeri **pari**, e una che gestisce i numeri **dispari**.

## 🧠 Obiettivo

Simulare due thread che accedono in modo **alternato** a una variabile condivisa, incrementandola uno alla volta.  
- Il **thread pari** stampa un messaggio quando il valore della variabile è pari.
- Il **thread dispari** stampa un messaggio quando il valore è dispari.

L'accesso è controllato tramite **due semafori**, per garantire l'alternanza corretta.

---

## ⚙️ Struttura del codice

- `condivisa`: variabile condivisa tra i due thread.
- `sem_t sPari`: semaforo che consente l'esecuzione del thread "pari".
- `sem_t sDispari`: semaforo che consente l'esecuzione del thread "dispari".
- `taskPari()`: funzione eseguita dal primo thread.
- `taskDispari()`: funzione eseguita dal secondo thread.

---

## 🚀 Esecuzione

### Requisiti

- Compilatore C++ compatibile con C++11 o superiore
- Sistema Linux o compatibile POSIX (per il supporto ai semafori `sem_t`)

### Compilazione

```bash
g++  -pthread nomefile.cpp -o programma
```
### Esecuzione
```bash
./programma
```

📌 Dettagli interessanti
    I semafori sPari e sDispari sono inizializzati rispettivamente a 0 e 1, in modo che il primo thread a partire sia quello dispari.
    I thread si synchronizzano attraverso sem_wait() e sem_post(), impedendo race condition e garantendo l'alternanza.
    È presente anche un mutex, ma in questo esempio non viene usato (può essere utile per estensioni future).

📚 Approfondimenti
    Questo progetto è utile per imparare:
    L’uso base dei semafori POSIX in C++
    La sincronizzazione dei thread
    L’alternanza controllata di operazioni su risorse condivise

