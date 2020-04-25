# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Tomislav Ivek <tomislav.ivek@gmail.com>

pkgbase=python-distro
pkgname=('python-distro' 'python2-distro')
pkgver=1.5.0
pkgrel=1
pkgdesc='Linux OS platform information API'
url='https://github.com/nir0s/distro'
arch=('any')
license=('Apache')
makedepends=('python-setuptools' 'python-sphinx' 'python2-setuptools')
checkdepends=('python-pytest' 'python2-pytest')
options=('!makeflags')
source=(https://github.com/nir0s/distro/archive/v${pkgver}/${pkgbase}-${pkgver}.tar.gz)
sha512sums=('35933ded65f99a86f9077af2d01528af337cda7b100f622fdcb0eaccd42baf7e4de77908870bfb1f575326cde85d6abc5a66f28a017c9813eb216dc55f3d94dd')
b2sums=('efc32a8ba6ffcd6eb7697d7b87ca5f84a91d7d9497249d43cd75fe51422e801111a480a48017d09f5101454d8af3341d0b5368a9093849c5078610cccaf60e53')

prepare() {
  cp -a distro-${pkgver}{,-py2}
}

build() {
  (cd distro-${pkgver}
    python setup.py build
    make man SPHINXBUILD=sphinx-build
  )
  (cd distro-${pkgver}-py2
    python2 setup.py build
    make man SPHINXBUILD=sphinx-build
  )
}

check() {
  (cd distro-${pkgver}
    py.test
  )
  (cd distro-${pkgver}-py2
    py.test2
  )
}

package_python-distro() {
  depends=('python' 'python-setuptools')
  cd distro-${pkgver}
  python setup.py install -O1 --root="${pkgdir}" --skip-build
  install -Dm 644 build_docs/man/ld.1 "${pkgdir}/usr/share/man/man1/${pkgname}.1"
  install -Dm 644 README.md CHANGELOG.md -t "${pkgdir}/usr/share/doc/${pkgname}"
}

package_python2-distro() {
  depends=('python2' 'python2-setuptools')
  cd distro-${pkgver}-py2
  python2 setup.py install -O1 --root="${pkgdir}" --skip-build
  install -Dm 644 build_docs/man/ld.1 "${pkgdir}/usr/share/man/man1/${pkgname}.1"
  install -Dm 644 README.md CHANGELOG.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  mv "${pkgdir}/usr/bin/distro"{,2}
}

# vim: ts=2 sw=2 et:
