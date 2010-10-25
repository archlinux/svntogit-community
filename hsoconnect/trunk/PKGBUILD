# Contributor: Geoffroy Carrier <geoffroy.carrier@aur.archlinux.org>
# Maintainer: Daniel J Griffiths <ghost1227@archlinux.us>

pkgname=hsoconnect
pkgver=1.2.18
pkgrel=7
pkgdesc="HSO command line connection utility"
arch=('any')
url="http://www.pharscape.org/forum/index.php?topic=743.0"
license=('GPL2')
depends=('pygtk' 'hsolink' 'ozerocdoff' 'dbus-python')
backup=('usr/share/hsoconnect/hsoconf/HSOconnect.cfg')
source=("${pkgname}-${pkgver}.tar.gz::http://www.pharscape.org/forum/index.php?PHPSESSID=f429fc2cadd473a6a7030d9ba04ff9f8&action=dlattach;topic=743.0;attach=28"
        'hsoconnect.sh'
        'HSOconnect.cfg'
        'hsoconnect.desktop')
md5sums=('ed7147b66838ca19114657ccffe441c7'
         'f0af2dfc63df9dd90f783d81e3c1824d'
         'ba44b2e3cae9e2c17408b109744d98cd'
         '54fa6503ea415d7bbf897af23e7055a9')

build() {
    cd ${srcdir}/${pkgname}-${pkgver}

    # python2 fix
    for file in $(find . -name '*.py' -print); do
        sed -i 's_#!.*/usr/bin/python_#!/usr/bin/python2_' $file
        sed -i 's_#!.*/usr/bin/env.*python_#!/usr/bin/env python2_' $file
    done

}

package() {
    cd ${srcdir}/${pkgname}-${pkgver}

    install -Dm755 -gnetwork ${srcdir}/${pkgname}.sh ${pkgdir}/usr/bin/${pkgname}
  
    install -Dm644 hsoconnect/HSOconnect.1 ${pkgdir}/usr/share/man/man1/HSOconnect.1

    install -d ${pkgdir}/usr/share/hsoconnect
    cp -r hsoconnect/hsoc hsoconnect/hsoconf ${pkgdir}/usr/share/hsoconnect
    rm ${pkgdir}/usr/share/hsoconnect/hsoconf/HSOconnect.cfg.def
    chown -R :network ${pkgdir}/usr/share/hsoconnect

    sed -i 's|dialout|network|' ${pkgdir}/usr/share/hsoconnect/hsoc/HSOconsole.py
    sed -i 's|PIDPATH =.*$|PIDPATH ="/tmp"|g' \
        ${pkgdir}/usr/share/hsoconnect/hsoc/HSOconnect.py

    install -D -m644 -gnetwork ${srcdir}/HSOconnect.cfg \
        ${pkgdir}/usr/share/hsoconnect/hsoconf/HSOconnect.cfg

    touch ${pkgdir}/usr/share/hsoconnect/hsoconf/{hsoconnect.log,transferlog}
    chown -R :network ${pkgdir}/usr/share/hsoconnect/hsoconf
    chmod -R g+rw ${pkgdir}/usr/share/hsoconnect/hsoconf

    install -d ${pkgdir}/usr/share/applications
    install -m644 ${srcdir}/hsoconnect.desktop ${pkgdir}/usr/share/applications/

    install -D hsoconnect/hsoconf/images/pengie/pengie-2-3232.png ${pkgdir}/usr/share/pixmaps/hsoconnect.png

    install -d ${pkgdir}/etc/
    ln -sf /usr/share/hsoconnect/hsoconf/HSOconnect.cfg ${pkgdir}/etc/hsoconnect
}
