# Maintainer: Aaron Schaefer <aaron@elasticdog.com>
pkgname=python-pexpect
pkgver=2.3
pkgrel=5
pkgdesc='A pure Python Expect-like module'
arch=('any')
url='http://pexpect.sourceforge.net/'
license=('MIT')
depends=('python2')
source=("http://downloads.sourceforge.net/sourceforge/pexpect/pexpect-$pkgver.tar.gz")
md5sums=('bf107cf54e67bc6dec5bea1f3e6a65c3')

build() {
  cd $srcdir/pexpect-$pkgver

  # python2 fix
  sed -i 's_#!/usr/bin/env python_#!/usr/bin/env python2_' FSM.py

  python2 setup.py install --root=$pkgdir
  install -D -m644 LICENSE $pkgdir/usr/share/licenses/$pkgname/LICENSE
}
