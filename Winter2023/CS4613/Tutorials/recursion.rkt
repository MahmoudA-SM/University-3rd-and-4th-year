#lang slideshow
(define (list-length list)
      (if (empty? list)
          0
          (+ 1 (list-length (cdr list)))))

    (module+ test
      (require rackunit)
      (define test-list '(1 2 3))

      (check-equal? (length test-list) (list-length test-list)))

(define (color-mapper p color-list)
  (for/list ([color color-list])
    (colorize (p 30) color)))


(color-mapper circle '("blue" "black"))