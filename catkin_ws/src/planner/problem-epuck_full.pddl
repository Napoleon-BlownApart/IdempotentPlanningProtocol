(define (problem robots-01)
   (:domain robots)
   (:objects
              x11 x21 x31 x41 x51 x61
              x12 x22 x32 x42 x52 x62
              x13 x23 x33 x43 x53 x63
              x14 x24 x34 x44 x54 x64
              x15 x25 x35 x45 x55 x65
              x16 x26 x36 x46 x56 x66 - intersection)
   (:init
     (at robot x36)

; Horizontal Paths

     (adjoin x11 x21)
     (adjoin x21 x31)
     (adjoin x31 x41)
     (adjoin x41 x51)
     (adjoin x51 x61)

     (adjoin x12 x22)
     (adjoin x22 x32)
     (adjoin x32 x42)
     (adjoin x42 x52)
     (adjoin x52 x62)

     (adjoin x13 x23)
     (adjoin x23 x33)
     (adjoin x33 x43)
     (adjoin x43 x53)
     (adjoin x53 x63)

     (adjoin x14 x24)
     (adjoin x24 x34)
     (adjoin x34 x44)
     (adjoin x44 x54)
     (adjoin x54 x64)

     (adjoin x15 x25)
     (adjoin x25 x35)
     (adjoin x35 x45)
     (adjoin x45 x55)
     (adjoin x55 x65)

     (adjoin x16 x26)
     (adjoin x26 x36)
     (adjoin x36 x46)
     (adjoin x46 x56)
     (adjoin x56 x66)

; Vertical Paths

     (adjoin x11 x12)
     (adjoin x12 x13)
     (adjoin x13 x14)
     (adjoin x14 x15)
     (adjoin x15 x16)

     (adjoin x21 x22)
     (adjoin x22 x23)
     (adjoin x23 x24)
     (adjoin x24 x25)
     (adjoin x25 x26)

     (adjoin x31 x32)
     (adjoin x32 x33)
     (adjoin x33 x34)
     (adjoin x34 x35)
     (adjoin x35 x36)

     (adjoin x41 x42)
     (adjoin x42 x43)
     (adjoin x43 x44)
     (adjoin x44 x45)
     (adjoin x45 x46)

     (adjoin x51 x52)
     (adjoin x52 x53)
     (adjoin x53 x54)
     (adjoin x54 x55)
     (adjoin x55 x56)

     (adjoin x61 x62)
     (adjoin x62 x63)
     (adjoin x63 x64)
     (adjoin x64 x65)
     (adjoin x65 x66)




; Static Blockages

; Horizontal Blockages

     (blocked x26 x36)
     (blocked x36 x46)
     (blocked x25 x35)
     (blocked x35 x45)
     (blocked x34 x44)
     (blocked x13 x23)
     (blocked x23 x33)

; Vertical Blockages

     (blocked x21 x22)
     (blocked x31 x32)
     (blocked x32 x33)
     (blocked x42 x43)
     (blocked x52 x53)

; Dynamic Blockages

;     (blocked x22 x23)
;     (blocked x12 x22)

   )

   (:goal 
       (and 
         (at robot x22)
       )
    )
)