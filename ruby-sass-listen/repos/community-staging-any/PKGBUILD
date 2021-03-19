# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Patrick Lühne <patrick-arch@luehne.de>

_gemname=sass-listen
pkgname=ruby-${_gemname}
pkgver=4.0.0
pkgrel=9
pkgdesc='Listens to file modifications and notifies you about the changes'
url='https://github.com/sass/listen'
arch=('any')
license=('MIT')
depends=('ruby' 'ruby-rb-inotify' 'ruby-rb-fsevent')
makedepends=('ruby-rdoc' 'ruby-rake' 'ruby-bundler' 'ruby-rspec')
options=('!emptydirs')
source=(https://github.com/sass/listen/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('799e1e70f86b4be671c3286ae860cbcec83d8a1311d67fb37956dc527e2961888094439fd8377d50c78798c494f19ddbed3a412f02e76e429dcc1717c93b7e19')
b2sums=('bb44a91a6fbdca1b6d1b8b2253efd1709fb89713631d9772ce91dab9bc701b197a6551391699f5566d3a75ae42f9958d5d6d8346de9f74b45d7b60d88cca5ee7')

prepare() {
  cd listen-${pkgver}
  sed -r 's|~>|>=|g' -i ${_gemname}.gemspec # don't give a fuck about rubys bla bla
  sed 's|git ls-files -z|find -type f -print0\|sed "s,\\\\./,,g"|' -i ${_gemname}.gemspec
}

build() {
  cd listen-${pkgver}
  gem build ${_gemname}.gemspec
}

check() {
  cd listen-${pkgver}
  # TODO: package rubocop and other deps
  #rake test
}

package() {
  cd listen-${pkgver}
  local _gemdir="$(gem env gemdir)"
  gem install --ignore-dependencies --no-user-install -i "${pkgdir}${_gemdir}" \
    -n "${pkgdir}/usr/bin" ${_gemname}-${pkgver}.gem
  install -Dm 644 README.md CHANGELOG.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 LICENSE.txt -t "${pkgdir}/usr/share/licenses/${pkgname}"

  cd "${pkgdir}/${_gemdir}"
  rm -r "${pkgdir}/${_gemdir}/cache"
}

# vim: ts=2 sw=2 et:
