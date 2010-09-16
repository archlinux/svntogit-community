# Contributor: Douglas Soares de Andrade <dsa@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=gazpacho
pkgver=0.7.2
pkgrel=4
pkgdesc="A GTK+ Glade-compatible GUI designer written in Python"
arch=('any')
license=('LGPL')
url=("http://gazpacho.sicem.biz")
options=('docs')
depends=('kiwi')
source=(http://ftp.acc.umu.se/pub/GNOME/sources/gazpacho/0.7/$pkgname-$pkgver.tar.bz2)
md5sums=('ca9c3c308a63194e6dcec3c932c98fbc')

build() {
    cd $srcdir/$pkgname-$pkgver
    python2 setup.py install --root=$pkgdir 
}
