(define (problem robots-01)
   (:domain robots)
   (:objects
              x11 x12 - intersection)
   (:init
     (at robot x11)
     (adjoin x11 x12)
   )
   (:goal 
       (and 
         (at robot x12)
       )
    )
)