# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>

pkgname=awxkit
_pkgname=awx
pkgver=10.0.0
pkgrel=1
pkgdesc="cli client and python library for ansible awx (tower)"
arch=('any')
url="https://github.com/ansible/awx"
license=('Apache')
depends=('python-six' 'python-yaml' 'python-requests')
makedepends=('python-pip' 'python-setuptools')
options=(!emptydirs)
source=("${pkgname}-${pkgver}.tar.gz::https://github.com/ansible/${_pkgname}/archive/${pkgver}.tar.gz")
sha512sums=('4980cef4e852ae5d77a3ec2e95efe57f4b5b72ca6d6084e3a4bd5791bf7df470777edba8cd29a89b3ea7c4b2bad254510401c006fa1778c6fcc0d5bd03c339e4')

build() {
    cd "${_pkgname}-${pkgver}/${pkgname}"
    python setup.py build
}

package() {
    cd "${_pkgname}-${pkgver}/${pkgname}"
    python setup.py install --root="$pkgdir/" --optimize=1
}
