#! /usr/bin/gcl -f 

;Sami Al-Qusus
;lab5 csci330
;Feb 22

; the listtype macro is used to check if every element of
;   a list passes a supplied type checking function, 
; and in the format
;   (listtype func arg1 arg2 ...)
;
; e.g. (listtype integerp 13 27 102)
;
; the macro expands into the form
;   T - when called with no data arguments (just the func)
;   (func arg1) - when called with one data argument
;   (if (func arg1) (func arg2)) - when called with two data arguments
;   (if (func arg1) (if (func arg2) (func arg3))) - when called with three data arguments
;   (if (func arg1) (if (func arg2) (if (func arg3) (func arg4)))) - with four arguments
;   etc
(defmacro listtype (func &rest args)
  (cond 
    ;treat func by itself as true
    ((null args) t)
    ; if there is only one element just use that as the value of the expression
    ((null (cdr args)) `(,func ,(car args)))
    ;since we will keep doing the computation over and over it might be an expensive computation therefore use gensym
    (t (let ((var (gensym)))
	 `(let ((,var (,func ,(car args))))
	    (if
	      ,var
	      (setf ,var (listtype ,func ,@(cdr args)))
	      ,var))))))
   


; display the expanded macro for use (listtype integerp 1 2)
(setf exp (macroexpand-1 '(listtype integerp 1 2)))
(format t "~%~%expansion of (listtype integerp 1 2) is:~%   ~A~%" exp)

; run the expanded macro and see what the result is
(format t "~%The result of (listtype integerp 1 2) is: ")
(cond
  ((listtype integerp 1 2) (format t "true~%"))
  (t (format t "false~%")))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; display the expanded macro for use (listtype integerp 1 2 3)
(setf exp (macroexpand '(listtype integerp 1 2 3)))
(format t "~%~%expansion of (listtype integerp 1 2 3) is:~%   ~A~%" exp)

; run the expanded macro and see what the result is
(format t "~%The result of (listtype integerp 1 2 3) is: ")
(cond
    ((listtype integerp 1 2 3) (format t "true~%"))
      (t (format t "false~%")))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; display the expanded macro for use (listtype integerp l l)
(setf exp (macroexpand-1 '(listtype integerp l l)))
(format t "~%~%expansion of (listtype integerp l l) is:~%   ~A~%" exp)

; run the expanded macro and see what the result is
(format t "~%The result of (listtype integerp l l) is: ")
(cond
    ((listtype integerp 'l 'l) (format t "true~%"))   
      (t (format t "false~%")))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; display the expanded macro for use (listtype integerp 1 2 l)
(setf exp (macroexpand-1 '(listtype integerp 1 2 l)))
(format t "~%~%expansion of (listtype integerp 1 2 l) is:~%   ~A~%" exp)

; run the expanded macro and see what the result is
(format t "~%The result of (listtype integerp 1 2 'l) is: ")
(cond
      ((listtype integerp 1 2 'l) (format t "true~%"))
            (t (format t "false~%")))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; display the expanded macro for use (listtype integerp 1 '(1 2 3))
(setf exp (macroexpand-1 '(listtype integerp 1 (1 2 3))))
(format t "~%~%expansion of (listtype integerp 1 '(1 2 3)) is:~%   ~A~%" exp)

; run the expanded macro and see what the result is
(format t "~%The result of (listtype integerp 1 '(1 2 3)) is: ")
(cond
      ((listtype integerp 1 '(1 2 3)) (format t "true~%"))
            (t (format t "false~%")))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(setf exp (macroexpand-1 '(listtype listp 1 (1 2 3))))
(format t "~%~%expansion of (listtype listp 1 '(1 2 3) is:~%   ~A~%" exp)

; run the expanded macro and see what the result is
(format t "~%The result of (listtype listp 1 '(1 2 3)) is: ")
(cond
        ((listtype  listp 1 '(1 2 3)) (format t "true~%"))
	            (t (format t "false~%")))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(setf exp (macroexpand-1 '(listtype listp (1) (1 2 3))))
(format t "~%~%expansion of (listtype listp '(1) '(1 2 3)) is:~%   ~A~%" exp)

; run the expanded macro and see what the result is
(format t "~%The result of (listtype listp '(1) '(1 2 3)) is: ")
(cond
        ((listtype listp '(1) '(1 2 3)) (format t "true~%"))
	            (t (format t "false~%")))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(setf exp (macroexpand-1 '(listtype numberp )))
(format t "~%~%expansion of (listtype numberp ) is:~%   ~A~%" exp)

; run the expanded macro and see what the result is
(format t "~%The result of (listtype numberp ) is: ")
(cond
          ((listtype numberp) (format t "true~%"))
	                      (t (format t "false~%")))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;






