(define (problem robots-03)
   (:domain robots)
   (:objects
              x111 x112 x113 x114
              x121 x122 x123 x124 - location

              robot1
              robot2 - agent

              )
   (:init
     (at robot1 x124)
     (occupied x124)
     (at robot2 x121)
     (occupied x121)

;  X Axis Paths

     (adjoin x111 x112)
     (adjoin x112 x113)
     (adjoin x113 x114)

     (adjoin x121 x122)
     (adjoin x122 x123)
     (adjoin x123 x124)

; Level 1 Y Axis Paths

     (adjoin x111 x121)
     (adjoin x112 x122)
     (adjoin x113 x123)
     (adjoin x114 x124)

; Dynamic Blockages

;     NONE

   )

   (:goal 
       (and 
         (at robot1 x121)
         (at robot2 x124)
       )
    )
)