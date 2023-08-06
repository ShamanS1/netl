set ns [new Simulator]

set nf [open out.nam w]
$ns namtrace-all $nf
proc finish {} {
      global ns nf
      $ns flush-trace
      close $nf
      exec nam out.nam &
      exit 0
      }


set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]

$ns duplex-link $n0 $n1 1.5mb 10ms DropTail
$ns duplex-link $n0 $n2 1.5mb 10ms DropTail
$ns duplex-link $n0 $n3 1.5mb 10ms DropTail
$ns duplex-link $n0 $n4 1.5mb 10ms DropTail
$ns duplex-link $n0 $n5 1.5mb 10ms DropTail

set tcp [new Agent/TCP]
set tcpsink [new Agent/TCPSink]
$ns attach-agent $n0 $tcp
$ns attach-agent $n1 $tcpsink
$ns attach-agent $n2 $tcpsink
$ns attach-agent $n3 $tcpsink
$ns attach-agent $n4 $tcpsink
$ns attach-agent $n5 $tcpsink

$ns connect $tcp $tcpsink

set ftp [new Application/FTP]
$ftp attach-agent $tcp
$ns at 0.2 "$ftp start"
$ns at 0.1 "$ftp stop"

$ns at 5.0 "finish"

$ns run




