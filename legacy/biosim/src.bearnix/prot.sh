#!/bin/bash

#
# Help script for the prot.C protein-protein
# simulation program. Users should NOT modify
# this script! Is meant as a help to create
# automated scripts.
#
# M. Lund, August 2005
#

function setjobid() {
  jobid=$1
  infile="prot.inp${jobid}"
}

function newjob() {
  setjobid `date +".%k%M%S"`
}

#
#set defaults...
#
macro=10
randomseed=13
cell_r=100
maxsep=100
minsep=0
temp=298
dielec=78.69
debye=1000.
prot_dp=7
prot_rot=2
ion_dp=80
nion1=0
chion1=1
nion2=0
chion2=-1
nion3=0
chion3=0
rion3=2.
hydrophob=0
springconst=0.5
springeqdist=8.
penalty=0.
monomer_dp=3.
titrate="yes"
rotate="yes"
translate="yes"
imdsupport="no"
hairy="no"
minsnapshot="no"
adjust_dp="yes"
hamaker=0
smear="no"
ph=7
exe="${biosim}/src/prot"
save_coord="no"
save_min=0
save_max=0

newjob

#------------------------------------------------

function seed() {
  randomseed=`date +"%s"`
}

function simulate() {
  makeinput
  $exe $infile
};

function cleanup() {
  rm -fR .coord${jobid} $infile
}

function setsalt() {
  debye=`python -c "from math import sqrt; print '%.1f' % (3.04/sqrt($1))"`
}

function makeinput() {
echo "
cell_r       $cell_r
temp         $temp
dielec       $dielec
debye        $debye
pH           $ph
randomseed   $randomseed
jobid        $jobid 
nion1        $nion1
nion2        $nion2 
nion3        $nion3 
chion1       $chion1 
chion2       $chion2 
chion3       $chion3 
rion3        $rion3
ion_dp       $ion_dp
protein1     $protein1 
protein2     $protein2 
prot_dp      $prot_dp
prot_rot     $prot_rot
maxsep       $maxsep
minsep       $minsep
hamaker      $hamaker 
hydrophob    $hydrophob
titrate      $titrate 
rotate       $rotate 
translate    $translate
imdsupport   $imdsupport
smear        $smear 
minsnapshot  $minsnapshot
springconst  $springconst 
springeqdist $springeqdist
monomer_dp   $monomer_dp 
hairy        $hairy 
macro        $macro
micro        $micro
adjust_dp    $adjust_dp
penalty      $penalty
save_coord   $save_coord
save_min     $save_min
save_max     $save_max
" > $infile
}
