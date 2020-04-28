# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=awxkit
_pkgname=awx
pkgver=11.1.0
pkgrel=1
pkgdesc="cli client and python library for ansible awx (tower)"
arch=('any')
url="https://github.com/ansible/awx"
license=('Apache')
depends=('python-six' 'python-yaml' 'python-requests')
makedepends=('python-pip' 'python-setuptools')
options=(!emptydirs)
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/ansible/${_pkgname}/archive/${pkgver}.tar.gz")
sha512sums=('6e683a254265e2d8ed878380dec3a98fa2856ae2fc12780de6ff74d21f624071c50e9f0a031bf5ac10e427cd28f8738bbdc664e81a94aecf406e6aeac9caab28')

build() {
    cd "${_pkgname}-${pkgver}/${pkgname}"
    python setup.py build
}

package() {
    cd "${_pkgname}-${pkgver}/${pkgname}"
    python setup.py install --root="$pkgdir/" --optimize=1
}
