# Maintainer: Kyle Keen <keenerd@gmail.com>
# Contributor: Will Shanks <wsha dot code at g mail dot com>

pkgbase=python-ptyprocess
pkgname=(python-ptyprocess python2-ptyprocess)
_pkgname=ptyprocess
pkgver=0.7.0
pkgrel=1
pkgdesc="Run a subprocess in a pseudo terminal"
url="https://github.com/pexpect/ptyprocess"
arch=('any')
license=('ISC')
depends=('python')
makedepends=('python-setuptools' 'python2-setuptools')
source=("https://pypi.io/packages/source/p/$_pkgname/$_pkgname-$pkgver.tar.gz"
        "LIC-pty-$pkgver::https://raw.githubusercontent.com/pexpect/ptyprocess/master/LICENSE")
sha512sums=('791d8f2e79900627215ce80ce67ee9c79173dbc08297c6219d5058f9b80c5e323b93049e6836a70c4073f43548d22e3cf310f2e9948ef12f96bcaa15b0ddb2f3'
            '0847180ae31aeae060c4f127f640d7501eea6285ccfd495f032cfcb09058a0ebfff55b75c8d005aa0d73e6401f61d8203c684f4002775436db1d5599aaba937d')

prepare() {
  cd "$srcdir"
  cp -r $_pkgname-$pkgver ${_pkgname}2-$pkgver
  mv "LIC-pty-$pkgver" LICENSE
}

package_python-ptyprocess() {
  cd "$srcdir/$_pkgname-$pkgver"
  python3 setup.py install --root="$pkgdir/" --prefix=/usr --optimize=0
  install -Dm644 "$srcdir/LICENSE" "$pkgdir/usr/share/licenses/python-$_pkgname/LICENSE"
}

package_python2-ptyprocess() {
  depends=('python2')
  cd "$srcdir/${_pkgname}2-$pkgver"
  python2 setup.py install --root="$pkgdir/" --prefix=/usr --optimize=0
  install -Dm644 "$srcdir/LICENSE" "$pkgdir/usr/share/licenses/python2-$_pkgname/LICENSE"
}
