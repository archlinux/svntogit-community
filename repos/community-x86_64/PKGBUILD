# $Id: PKGBUILD 140196 2011-10-09 08:27:16Z angvp $
# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Angel Velasquez <angvp@archlinux.org> 
# Contributor: Sergej Pupykin <sergej@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgbase=python-m2crypto
pkgname=(python2-m2crypto python-m2crypto)
pkgver=0.30.1
pkgrel=2
pkgdesc="A crypto and SSL toolkit for Python"
arch=('x86_64')
url="https://pypi.python.org/pypi/M2Crypto"
license=('BSD')
makedepends=('python' 'python-setuptools'
             'python2' 'python2-setuptools'
	     'swig')
source=("${pkgname}-${pkgver}.tar.gz::https://gitlab.com/m2crypto/m2crypto/repository/${pkgver}/archive.tar.gz"
	"LICENSE")
sha256sums=('02eacd9b47aace718bb64cd2233e225aa44db8d60e9f077fb176a36b79ed14a6'
            '4eca478396f4b2b020729a111fce3f096456d74500bfd8f2b0388c3c69f997c0')

prepare() {
  mv m2crypto-${pkgver}-* m2crypto-${pkgver}
  cp -a m2crypto-$pkgver{,-py2}
}

build(){
  cd "$srcdir/m2crypto-$pkgver-py2"
  python2 setup.py build

  cd "$srcdir/m2crypto-$pkgver"
  python setup.py build

}

package_python2-m2crypto() {
  depends=('python2' 'openssl' 'python2-typing')
  cd "${srcdir}/m2crypto-${pkgver}-py2"
  python2 setup.py install --root="${pkgdir}/" --optimize=1 --skip-build
  install -D -m644 "$srcdir"/LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}

package_python-m2crypto() {
  depends=('python' 'openssl')
  cd "${srcdir}/m2crypto-${pkgver}"
  python setup.py install --root="${pkgdir}/" --optimize=1 --skip-build
  install -D -m644 "$srcdir"/LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
