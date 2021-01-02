; Wave.s, graph of a sin wave using pcscheme on MS-DOS  

(init-graph)

; Only if we're loading with the editor 
(define (return-ed)
  (close-graph)
  (ed "wave.s"))


; Some variables  
(define max-x (car (get-max-xy))) 
(define max-y (cdr (get-max-xy)))
(define screen-half (/ max-y 2))

; Draw the x-axis
(line (cons 0 screen-half) (cons max-x screen-half))
; Draw the label
(out-text-xy (cons screen-half 50) "Simple Sin Wave Graph")
; Amplitude and frequency
(define amp 50)
(define freq 45)

; Our loop
(let loop ((x 0))
  (letrec (
	 (y (* amp (sin (* x (/ PI freq)))))
	 (y2 (- screen-half y))
       )
    (put-pixel (cons x y2) 'WHITE)
  )
  (if (< x max-x)
      (loop (+ x 0.5))))




