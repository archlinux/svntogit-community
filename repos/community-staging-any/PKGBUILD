# Maintainer: Jelle van der Waa <jelle@archlinux.org>
# Contributor: Husam Bilal <husam212 AT gmail DOT com>

_name=intervals
pkgname="python-${_name}"
pkgver=0.9.2
pkgrel=4
pkgdesc='Python tools for handling intervals (ranges of comparable objects).'
url='https://github.com/kvesteri/intervals'
depends=('python' 'python-infinity')
checkdepends=('python-pytest')
makedepends=('python' 'python-setuptools')
license=('BSD')
arch=('any')
source=("https://files.pythonhosted.org/packages/source/${_name::1}/${_name}/${_name}-${pkgver}.tar.gz"
        'pytest5.patch')
sha512sums=('40da5f7630bc84dbd47196e7e84f94701730b4f2ee71294edfaecfc9187f5c05333fc79502c315d5962c29c9c2a50c8e471980c98764d7c0581d33383a487e4a'
            'af545bec7d8157259197e045396d69ac1791b5e0420056fca69bea444cceacaa208ae568fd80792f614e1c775611ea22c48521bdd47dbdd976a699c150835f96')

prepare() {
  cd "${srcdir}/${_name}-${pkgver}"
  patch -Np1 -i ../pytest5.patch
}
build() {
  cd "${srcdir}/${_name}-${pkgver}"
  python setup.py build
}

check() {
  cd "${srcdir}/${_name}-${pkgver}"
  py.test
}

package() {
  cd "${srcdir}/${_name}-${pkgver}"
  python setup.py install --root="${pkgdir}/" --optimize=1
  install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
