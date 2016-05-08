#!/bin/bash
# Let the student work on the concept map

# Load scripts
. ../../testing_cpp_gui_applications_tutorial/scripts/get_dialog_id.sh

# Variables
myexe="../../build-BrainweaverDeveloper-Desktop-Debug/BrainweaverDeveloper"
mycmp="scenario1.cmp"
mycmp_result="scenario1_result.cmp"

####################################
# Check executable
####################################
if [ -e /$myexe ] # slash is obligatory?
then
  echo $mytestname": FAIL (executable '"$myexe"' not found)"
  exit
fi

####################################
# Input file must be present
####################################
if [ ! -e $mycmp ]
then
  echo "File "$mycmp" not found, line "$LINENO
  exit 1
fi

####################################
# Delete result file
####################################
if [ -e $mycmp_result ]
then
  echo "File "$mycmp_result" found, deleting it"
  rm $mycmp_result
fi

if [ -e $mycmp_result ]
then
  echo "File "$mycmp_result" could not be deleted"
  exit 1
fi

####################################
# Start application
####################################
$myexe &
sleep 1

####################################
# Main menu, choose '1. Student'
####################################
id=`get_dialog_id "Menu voor de ontwikkelaar"`
if [ -z $id ]
then
  echo "ID not found, line "$LINENO
  exit 1
fi
xdotool windowactivate $id key alt+1 sleep 0.2

####################################
# 'Kies een assessment bestand'
####################################
id=`get_dialog_id "Kies een assessment bestand"`
if [ -z $id ]
then
  echo "ID not found, line "$LINENO
  exit 1
fi
xdotool windowactivate $id key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete key Delete
# Type filename
xdotool windowactivate $id type $mycmp
# OK
xdotool windowactivate $id key alt+o sleep 0.1

####################################
# 'Mijn persoonlijke werktheorie, programma voor de student'
# Type your name
####################################
id=`get_dialog_id "Mijn persoonlijke werktheorie, programma voor de student"`
if [ -z $id ]
then
  echo "ID not found, line "$LINENO
  exit 1
fi
xdotool windowactivate $id type "John Doe"
# &Begin
xdotool windowactivate $id key alt+b sleep 0.2

####################################
# 'Mijn persoonlijke werktheorie, programma voor de student'
# Beginnen mey &Associeren
####################################
id=`get_dialog_id "Mijn persoonlijke werktheorie, programma voor de student"`
if [ -z $id ]
then
  echo "ID not found, line "$LINENO
  exit 1
fi
# &Associate
xdotool windowactivate $id key alt+a sleep 0.2



####################################
# 'Associeer- en cluster-scherm'
# Add some associations
####################################
id=`get_dialog_id "Associeer- en cluster-scherm"`
if [ -z $id ]
then
  echo "ID not found, line "$LINENO
  exit 1
fi
# Text to add
xdotool windowactivate $id type "hard to make up"
# Add 
xdotool windowactivate $id key Tab Return
# Text to add
xdotool windowactivate $id type "concise"
# Add 
xdotool windowactivate $id key Tab Return
# Text to add
xdotool windowactivate $id type "precise"
# Add 
xdotool windowactivate $id key Tab Return
# Text to add
xdotool windowactivate $id type "English"
# Add 
xdotool windowactivate $id key Tab Return
# Text to add
xdotool windowactivate $id type "not too long"
# Add 
xdotool windowactivate $id key Tab Return

# Save
xdotool windowactivate $id key alt+s sleep 0.2

####################################
# 'Sla de clustering op'
####################################
id=`get_dialog_id "Sla de clustering op"`
if [ -z $id ]
then
  echo "ID not found, line "$LINENO
  exit 1
fi

xdotool windowactivate $id type $mycmp_result 
xdotool windowactivate $id sleep 0.1 key alt+o sleep 0.2

####################################
# Check newly saved file
####################################
if [ ! -e $mycmp_result ]
then
  echo "File "$mycmp_result" not found, line "$LINENO
  exit 1
fi
# Show that the cluster has changed
echo "Before: "
egrep "<cluster>.*</cluster>" $mycmp -o
echo "After: "
egrep "<cluster>.*</cluster>" $mycmp_result -o