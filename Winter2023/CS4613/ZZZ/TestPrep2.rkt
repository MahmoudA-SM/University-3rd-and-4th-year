#lang racket/base
(module question1 plait #:untyped
  (define-type LAE
    [Num  (val : Number)]
    [Add  (l : LAE) (r : LAE)]
    [Id   (name : Symbol)]
    [Let1 (name : Symbol) (val : LAE) (expr : LAE)]
    [Let2 (name1 : Symbol) (val1 : LAE) (name2 : Symbol) (val2 : LAE) (expr : LAE)])
  (test (let ([x 1] [y 2])
          (let ([x y] [y x])
            (- x y)))
        1)
  (define (subst expr from to)
    (type-case LAE expr
      [(Num n) expr]
      [(Add l r) (Add (subst l from to) (subst r from to))]
      [(Id name) (if (eq? name from) to expr)]
      [(Let1 bound-id named-expr bound-body)
       (Let1 bound-id
             (subst named-expr from to)
             (if (eq? bound-id from)
                 bound-body
                 (subst bound-body from to)))]
      [(Let2 bound-id1 named-expr1 bound-id2 named-expr2 bound-body)
       (Let2 bound-id1
             (subst named-expr1 from to)
             bound-id2
             (subst named-expr2 from to)
             (if (or (eq? bound-id1 from)
                     (equal? bound-id2 from))
                 bound-body
                 (subst bound-body from to)))]))

  (test (subst
         (Let2 'x (Id 'x) 'y (Id 'y) (Id 'x))
         'x
         (Num 5))
        (Let2 'x (Num 5) 'y (Id 'y) (Id 'x)))

  (test (subst
         (Let2 'x (Id 'x) 'y (Id 'y) (Id 'y))
         'y
         (Num 5))
        (Let2 'x (Id 'x) 'y (Num 5) (Id 'y)))

  (test (subst
         (Let2 'x (Id 'x) 'y (Id 'y) (Id 'z))
         'z
         (Num 5))
        (Let2 'x (Id 'x) 'y (Id 'y) (Num 5)))
  )
(module question2 plait #:untyped
  (test
   (let ([sum (lambda (self)
                (lambda (n)
                  (if (empty? n) 0
                      (+ (first n) ((self self)(rest n))))))])
     ((sum sum) '(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18)))
   171)
  )
(module question3 plait #:untyped
  (define-type FLANG
    [Num  (val : Number)]
    [Add  (l : FLANG) (r : FLANG)]
    [Id   (name : Symbol)]
    [Let1 (id : Symbol) (named-expr : FLANG) (bound-body : FLANG)]
    [Fun  (param : Symbol) (body : FLANG)]
    [Call (fun : FLANG) (val : FLANG)])

  (define (bound name env)
    (if (none? (hash-ref env name)) #f #t))

  (define (extend name env)
    (hash-set env name #t))

  (define empty-env (hash empty))

  (test (bound 'x empty-env) #f)
  (test (bound 'x (extend 'y (extend 'x empty-env))) #t)

  (define (union the-set other-set)
    (hash (map (lambda (x) (pair x #t))
               (append (hash-keys the-set) (hash-keys other-set)))))

  (define (free-vars expr env)
    (type-case FLANG expr
      [(Num n) empty-env]
      [(Add l r) (union (free-vars l env) (free-vars r env))]
      [(Let1 bound-id named-expr bound-body) (union
                                              (free-vars named-expr env)
                                              (free-vars bound-body (extend bound-id env)))]
      [(Id name) (if (bound name env) empty-env (extend name empty-env))]
      [(Fun bound-id bound-body) (free-vars bound-body (extend bound-id env))]
      [(Call fun-expr arg-expr) (union (free-vars fun-expr env)
                                       (free-vars arg-expr env))]))

  (test (free-vars (Num 3) empty-env) empty-env)
  (test (free-vars (Add (Id 'x) (Num 3)) empty-env) (extend 'x empty-env))
  (test (free-vars (Add (Id 'x) (Num 3)) (extend 'x empty-env)) empty-env)
  (test (free-vars (Let1 'x (Num 3) (Add (Id 'x) (Num 3))) empty-env) empty-env)
  (test (free-vars (Let1 'x (Num 3) (Add (Id 'x) (Num 3))) (extend 'x empty-env)) empty-env)
  (test (free-vars (Let1 'x (Id 'y) (Add (Id 'x) (Num 3))) (extend 'x empty-env)) (extend 'y empty-env))
  (test (free-vars (Fun 'x  (Add (Id 'x) (Num 3))) (extend 'x empty-env)) empty-env)
  (test (free-vars (Call (Id 'x) (Id 'x)) empty-env) (extend 'x empty-env))
  (test (free-vars (Call (Id 'x) (Id 'x)) (extend 'x empty-env)) empty-env)
  )
(module question4 plait #:untyped
  (define-type FLANG
    [Num  (val : Number)]
    [Add  (l : FLANG) (r : FLANG)]
    [Id   (name : Symbol)]
    [Let1 (id : Symbol) (named-expr : FLANG) (bound-body : FLANG)]
    [Lam  (param : Symbol) (body : FLANG)]
    [CallDyn (fun : FLANG) (val : FLANG)]
    [Call (fun : FLANG) (val : FLANG)])
  (define-type ENV
    [EmptyEnv]
    [Extend (name : Symbol) (val : VAL) (rest : ENV)])

  (define-type VAL
    [NumV (n : Number)]
    [LamV (arg : Symbol) (body : FLANG) (env : ENV)])

  (define (lookup name env)
    (type-case ENV env
      [(EmptyEnv) (error 'lookup "no-binding")]
      [(Extend id val rest-env) (if (eq? id name) val (lookup name rest-env))]))
  (define (interp expr env)
    (type-case FLANG expr
      [(Num n) (NumV n)]
      [(Add l r)
       (NumV (+ (NumV-n (interp l env)) (NumV-n (interp r env))))]
      [(Let1 bound-id named-expr bound-body)
       (interp bound-body (Extend bound-id (interp named-expr env) env))]
      [(Id name) (lookup name env)]
      [(Lam bound-id bound-body) (LamV bound-id bound-body env)]
      [(CallDyn fun-expr arg-expr)
       (let ([fval (interp fun-expr env)])
         (type-case VAL fval
           [(LamV bound-id bound-body f-env)
            (interp bound-body (Extend bound-id (interp arg-expr env) env))]
           [else (error 'interp "non-function")]))]
      [(Call fun-expr arg-expr)
       (let ([fval (interp fun-expr env)])
         (type-case VAL fval
           [(LamV bound-id bound-body f-env)
            (interp bound-body (Extend bound-id (interp arg-expr env) f-env))]
           [else (error 'interp "non-function")]))]))
  (define (example body)
    (Let1 'x (Num 3)
          (Let1 'f (Lam 'y (Add (Id 'x) (Id 'y)))
                (Let1 'x (Num 5)
                      body))))

  (test (interp (example (Call (Id 'f) (Num 4))) (EmptyEnv))
        (NumV 7))

  (test (interp
         (example (CallDyn (Id 'f) (Num 4))) (EmptyEnv))
        (NumV 9))
  )


(module question5 plait #:untyped
  (define (typecheck [ae : AE]) : Type
    (type-case AE ae
      [(Num n) (NumT)]
      [(Bool v) (BoolT)]
      [(Add l r) (let
                     ((typel (typecheck l))
                   (typer (typecheck r)))
                   (if (equal? typel typer)
                       typer
                       (error 'type-mismatch "type mismatch")))
                   
                              ]))

  (define-type AE
    [Num  (val : Number)]
    [Bool (val : Boolean)]
    [Add  (l : AE) (r : AE)])

  (define-type Type
    [NumT]
    [BoolT])



  (test (typecheck (Add (Num 1) (Num 2))) (NumT))
  (test (typecheck (Add (Bool #t) (Bool #f))) (BoolT))
  (test/exn (typecheck (Add (Bool #t) (Num 1))) "type mismatch")
  (test/exn (typecheck (Add (Num 1) (Bool #t))) "type mismatch")


  )
(require (only-in 'question1))
(require (only-in 'question2))
(require (only-in 'question3))
(require (only-in 'question4))
(require (only-in 'question5))