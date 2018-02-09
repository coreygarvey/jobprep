# Corey Garvey - July 5
# Python List - Resizing


def lists():
    a = [] 
    for i in range(0,12):
        a.append(i*4)

    print "print a: "
    print a
    
    print "print len(a): "
    print len(a)
    
    print "print 4 in a: "
    print 4 in a

    print "for x in a: print x/2: "
    for x in a: print x/2

    print "print a[2]: "
    print a[2]

    print "print a[-2]: "
    print a[-2]

    print "print a.count(12): "
    print a.count(12)
