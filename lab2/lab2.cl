#! /usr/bin/gcl -f 

;Sami Al-Qusus
;csci330
;Jan 19, 2018
;Lab1

(defun firstN (L N)
  (cond
   ((not (listp L)) L)
   ((not (integerp N)) L)
   ((< N 1) nil)
   ((>= N (list-length L)) L)
   (t (append (list(car L))(firstN (cdr L) (- N 1))))
  ))

(defun lastN (L N)
  (cond
    ((not (listp L)) L)
    ((not (integerp N)) L)
    ((< N 1) nil)
    ((>= N (list-length L)) L)
    (t (lastN (cdr L) N))
  ))

(defun rotateN (L N)
  (cond
    ((not (listp L)) L)
    ((not (and (integerp N) (> N 0))) L)
    ((<= N 0) L)
    (t (rotateN (append (cdr L) (list(car L))) (- N 1)))
   ))

(defun main()
  (let
    ((L 0) (N 0))
    (format t "Please enter the values for L and N: ~%")
    (setf L(read))
    (setf N(read))
    (format t "firstN of ~A and ~A is: ~A ~%" L N (firstN L N))
    (format t "lastN of ~A and ~A is: ~A ~%" L N (lastN L N))
    (format t "rotateN of ~A and ~A is: ~A ~%" L N (rotateN L N))
    ))

(main)




