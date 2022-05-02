# Maintainer: Tim Meusel <tim@bastelfreak.de>
# Contributor: Christian Rebischke <chris.rebischke@archlinux.org>

_gemname='deep_merge'
pkgname="ruby-${_gemname}"
pkgver=1.2.2
pkgrel=1
pkgdesc='Recursively merge Ruby hashes'
arch=('any')
url="https://github.com/danielsdeleo/${_gemname}"
license=('MIT')
makedepends=('ruby-rdoc')
checkdepends=('ruby-rake' 'ruby-minitest' 'ruby-test-unit')
depends=('ruby')
options=(!emptydirs)
source=("${url}/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz")
sha512sums=('35d3d9e23b77ab2cabeac3ea65ebda3ad5373441bfb6ed376786c20f8f0cea58755273e08d02799099ee483d2ee7de804977c82cd4e499ba0f202003d5a6f757')

build() {
  cd "${srcdir}/${_gemname}-${pkgver}"
  gem build "${_gemname}.gemspec"
}

check() {
  cd "${srcdir}/${_gemname}-${pkgver}"
  rake test
}

package() {
  cd "${srcdir}/${_gemname}-${pkgver}"
  local _gemdir="$(gem env gemdir)"
  gem install --verbose --ignore-dependencies --no-user-install --install-dir "${pkgdir}/${_gemdir}" --bindir "${pkgdir}/usr/bin" "${_gemname}-${pkgver}.gem"

  install -Dm 644 CHANGELOG README.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}/"

  rm -rf "${pkgdir}/${_gemdir}/cache"
}

# vim: ts=2 sw=2 et:
