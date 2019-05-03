#! /usr/bin/gcl -f 

;Sami Al-Qusus
;csci330
;Feb 2, 2018
;Lab3

(defun final (L)
  ;stores true or false for if L is a list of list to be used later in cond
  (defvar z t)
  (cond ((listp L)
  (dolist
     (x L)
     (if (listp x)
      (setf z(and z (not t)))
      (setf z(and z t))))))
  ;actual function stuff
  (cond
    ((not (listp L)) nil)
    (z nil)
    (t (mapcar 'last L))
    ))


(defun firstN (L N)
  (cond
    ((not (listp L)) nil)
    ((not (integerp N)) nil)
    ((< N 1) nil)
    ((>= N (list-length L)) L)
    (t (append (list(car L))(firstN (cdr L) (- N 1))))
    ))


(defun firsts (L N)
  
  ;stores true or false for if L is a list of list to be used later in cond
  (defvar z t)
  (cond ((listp L)
  (dolist
    (x L)
    (if (listp x)
      (setf z(and z (not t)))
      (setf z(and z t))))))
  ;actual function stuff
  (cond
    ((not (integerp N)) nil)
    ((< N 0) nil)
    ((not (listp L)) nil)
    (z nil)
    (t (map 'list 'firstN L (make-list (length L) :initial-element N)))
    ))

(defun main()
  (let
    ((L 0) (N 0))
    (format t "Please enter the values for L and N: ~%")
    (setf L(read))
    (setf N(read))
    (format t "~%L is: ~A ~%N is: ~A ~% " L N)
    (format t "~%(firsts L N) gives ~%")
    (format t "(firsts ~A ~A) is: ~% ==> ~A ~%" L N (firsts L N))
    (format t "~%(final (firsts L N) gives ~%")
    (format t "(final (firsts ~A ~A)) is: ~% ==> ~A ~%" L N (final (firsts L N)))
    ))
(main)
     

