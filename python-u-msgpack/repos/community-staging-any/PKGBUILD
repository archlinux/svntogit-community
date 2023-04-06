# Contributor: Eli Schwartz <eschwartz@archlinux.org>

_pkgname=u-msgpack-python
pkgname='python-u-msgpack'
pkgver=2.7.2
pkgrel=2
arch=('any')
url="https://github.com/vsergeev/${_pkgname}"
license=('MIT')
pkgdesc="portable, lightweight MessagePack serializer and deserializer for Python"
depends=('python')
makedepends=('python')
checkdepends=('python-pytest')
source=("https://files.pythonhosted.org/packages/source/${_pkgname:0:1}/${_pkgname}/${_pkgname}-${pkgver}.tar.gz")
sha256sums=('e86f7ac6aa0ef4c6c49f004b4fd435bce99c23e2dd5d73003f3f9816024c2bd8')
b2sums=('0365e4e778c9979d9154d8a267ba3bdaad9b2ef808723d2ae89e078fc0c8d76aebab234f1723985cf3b288274123e49571607599d6087ea234e3e8dc11e3a302')

build() {
    cd ${_pkgname}-${pkgver}

    python setup.py build
}

check() {
    cd ${_pkgname}-${pkgver}

    pytest
}

package() {
    cd ${_pkgname}-${pkgver}
    python setup.py install --root="${pkgdir}" --optimize=1 --skip-build

    install -Dm644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
}
