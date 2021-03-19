# Maintainer: Tim Meusel <tim@bastelfreak.de>

_gemname='multipart-parser'
pkgname="ruby-${_gemname}"
pkgver=0.1.1
pkgrel=2
pkgdesc='A simple parser for multipart MIME messages, written in Ruby'
arch=('any')
url='https://github.com/danabr/multipart-parser'
license=('MIT')
depends=('ruby')
makedepends=('ruby-rdoc' 'git')
checkdepends=('ruby-test-unit' 'ruby-bundler' 'ruby-rake')
options=('!emptydirs')
source=("git+${url}#commit=9b9c4acb7c441d20a2c5a596ec4aecdecf6ebfe9" 'fix-broken-tests.patch')
sha512sums=('SKIP'
            'b955ab17fa167411a18ca950ee29a0db37e00ebd70e492a149a44f1937cc3eefcaf22201fa7d8c4464fcffc96b65829ef3741501bb32022ccbb770eb057a428d')

prepare() {
  cd "${srcdir}/${_gemname}"
  # cherry-picked the bugfix from https://github.com/danabr/multipart-parser/pull/5/files
  patch -p1 -N -i "${srcdir}/fix-broken-tests.patch"
}

build() {
  cd "${srcdir}/${_gemname}"
  gem build "${_gemname}.gemspec"
}

check() {
  cd "${srcdir}/${_gemname}"
  rake test
}

package() {
cd "${srcdir}/${_gemname}"
  local _gemdir="$(gem env gemdir)"
  gem install --verbose --ignore-dependencies --no-user-install --install-dir "${pkgdir}/${_gemdir}" --bindir "${pkgdir}/usr/bin" "${_gemname}-${pkgver}.gem"

  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}/"

  install -Dm 644 README -t "${pkgdir}/usr/share/doc/${pkgname}"

  rm -rf "${pkgdir}/${_gemdir}/cache"
}
