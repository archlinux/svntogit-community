# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Angel Velasquez <angvp@archlinux.org> 
# Contributor: Sergej Pupykin <sergej@aur.archlinux.org>
# Contributor: William Rea <sillywilly@gmail.com>

pkgname=python-m2crypto
pkgver=0.38.0
pkgrel=5
pkgdesc="A crypto and SSL toolkit for Python"
arch=('x86_64')
url="https://pypi.python.org/pypi/M2Crypto"
license=('BSD')
depends=('python' 'openssl')
makedepends=('python-setuptools' 'swig')
source=("${pkgname}-${pkgver}.tar.gz::https://gitlab.com/m2crypto/m2crypto/-/archive/${pkgver}/${pkgname#python-}-${pkgver}.tar.gz"
        "LICENSE")
sha256sums=('ef0df09fd2db71e2470e62f4e588f633b05a4dc7395bfa67e81c65a8a959a719'
            '4eca478396f4b2b020729a111fce3f096456d74500bfd8f2b0388c3c69f997c0')

build(){
  cd "m2crypto-$pkgver"
  python setup.py build

}

package() {
  cd "m2crypto-${pkgver}"
  python setup.py install --root="${pkgdir}/" --optimize=1 --skip-build
  install -D -m644 "$srcdir"/LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
