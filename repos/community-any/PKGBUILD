# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=awxkit
_pkgname=awx
pkgver=12.0.0
pkgrel=1
pkgdesc="cli client and python library for ansible awx (tower)"
arch=('any')
url="https://github.com/ansible/awx"
license=('Apache')
depends=('python-six' 'python-yaml' 'python-requests')
makedepends=('python-pip' 'python-setuptools')
options=(!emptydirs)
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/ansible/${_pkgname}/archive/${pkgver}.tar.gz")
sha512sums=('7af0dfab28af282e22c7b31a3469fa27cf9a80c2fbf4984d3e7e3914835452d2318b96e8f6c870da6c55941e0365757997560d88db690c127dc14b52fee816c4')

build() {
    cd "${_pkgname}-${pkgver}/${pkgname}"
    python setup.py build
}

package() {
    cd "${_pkgname}-${pkgver}/${pkgname}"
    python setup.py install --root="$pkgdir/" --optimize=1
}
