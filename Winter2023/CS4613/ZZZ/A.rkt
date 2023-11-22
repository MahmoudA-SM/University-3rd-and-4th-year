#lang plait
(define PI : Number 3.14159)
(* PI 10)
PI

(define (circle-area r) (* PI (* r r)))
(circle-area 10)


(define (f x)
  (* x (+ x 1)))

(f 2)

(define-type Reptile
  {Snake (name : Symbol)
         (weight : Number)
         (food : Symbol)}
  {Tiger (name : Symbol)
         (weight : Number)
         (food : Symbol)
         })
(define n (Tiger 'MMM 400 'Animals))



(define (animal-name animal)
  (type-case Reptile animal
  ((Snake name weight food) name)
  ((Tiger name weight food) name)))

(animal-name n)
(define snke (Snake 'mas 700 'rats))
(animal-name snke)

(define (animal-food animal)
  (type-case Reptile animal
    ((Snake name weight food) food)
    ((Tiger name weight food) food)))

(animal-food snke)
(animal-food n)

(define (animal-weight animal)
  (type-case Reptile animal
    ((Snake name weight food) weight)
    ((Tiger name weight food) weight)))
(animal-weight snke)
(animal-weight n)

(define (digits number)
  (cond
    ((<= number 9) (some 1))
    ((<= number 99) (some 2))
    ((<= number 999) (some 3))
    (else (none))))

(digits 9)
(digits 99)
(digits 999)
(digits 191919)

(define (reverse-lst lst)
  (local
    [(define (reverse lst newlst)
      (cond
        [(empty? lst) newlst]
        [else
         (reverse (rest lst)
                  (cons (first lst) newlst))]))]
    (reverse lst empty)))

(test (reverse-lst (list 1 2 3)) (list 3 2 1))


